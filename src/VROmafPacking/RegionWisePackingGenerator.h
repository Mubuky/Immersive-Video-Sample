/*
 * Copyright (c) 2019, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

//!
//! \file:   RegionWisePackingGenerator.h
//! \brief:  Region wise packing generator wrapper class definition
//! \detail: Define the basic operation of region wise packing generator.
//!
//! Created on April 30, 2019, 6:04 AM
//!

#ifndef _REGIONWISEPACKINGGENERATOR_H_
#define _REGIONWISEPACKINGGENERATOR_H_

#include <list>
#include <map>

#include "OmafPackingCommon.h"
#include "VROmafPacking_data.h"
#include "definitions.h"
#include "MediaStream.h"
#include "OMAFPackingPluginAPI.h"

VCD_NS_BEGIN

//!
//! \class RegionWisePackingGenerator
//! \brief Define the basic operation of region wise packing generator
//!

class RegionWisePackingGenerator
{
public:
    //!
    //! \brief  Constructor
    //!
    RegionWisePackingGenerator();

    //!
    //! \brief  Destructor
    //!
    ~RegionWisePackingGenerator();

    //!
    //! \brief  Initialize the region wise packing generator
    //!
    //! \param  [in] rwpkGenPluginPath
    //!         pointer to the OMAF packing plugin path
    //! \param  [in] rwpkGenPluginName
    //!         pointer to the OMAF packing plugin name
    //! \param  [in] streams
    //!         pointer to the media streams map set up in OmafPackage
    //! \param  [in] videoIdxInMedia
    //!         pointer to the index of each video in media streams
    //! \param  [in] tilesNumInViewport
    //!         the number of tiles in viewport
    //! \param  [in] tilesInViewport
    //!         pointer to tile information of all tiles in viewport
    //! \param  [in] finalViewportWidth
    //!         the final viewport width calculated by 360SCVP library
    //! \param  [in] finalViewportHeight
    //!         the final viewport height calculated by 360SCVP library
    //!
    //! \return int32_t
    //!         ERROR_NONE if success, else failed reason
    //!
    int32_t Initialize(
        const char *rwpkGenPluginPath,
        const char *rwpkGenPluginName,
        std::map<uint8_t, MediaStream*> *streams,
        uint8_t *videoIdxInMedia,
        uint8_t tilesNumInViewport,
        TileDef *tilesInViewport,
        int32_t finalViewportWidth,
        int32_t finalViewportHeight);

    //!
    //! \brief  Generate the region wise packing information for
    //!         specified viewport
    //!
    //! \param  [in]  viewportIdx
    //!         the index of specified viewport
    //! \param  [out] dstRwpk
    //!         pointer to the region wise packing information for
    //!         the specified viewport
    //!
    //! \return int32_t
    //!         ERROR_NONE if success, else failed reason
    //!
    int32_t GenerateDstRwpk(
        uint8_t viewportIdx,
        RegionWisePacking *dstRwpk);

    //!
    //! \brief  Generate the tiles merging direction information for
    //!         specified viewport
    //!
    //! \param  [in]  viewportIdx
    //!         the index of specified viewport
    //! \param  [out] tilesMergeDir
    //!         pointer to the tiles merging direction information for
    //!         the specified viewport
    //!
    //! \return int32_t
    //!         ERROR_NONE if success, else failed reason
    //!
    int32_t GenerateTilesMergeDirection(
        uint8_t viewportIdx,
        TilesMergeDirectionInCol *tilesMergeDir);

    //!
    //! \brief  Get the number of tiles in one row in viewport
    //!
    //! \return uint8_t
    //!         the number of tiles in one row in viewport
    //!
    uint8_t GetTilesNumInViewportRow();

    //!
    //! \brief  Get the number of tile rows in viewport
    //!
    //! \return uint8_t
    //!         the number of tile rows in viewport
    //!
    uint8_t GetTileRowNumInViewport();

    //!
    //! \brief  Get the width of tiles merged picture
    //!
    //! \return uint32_t
    //!         the width of tiles merged picture
    //!
    uint32_t GetPackedPicWidth();

    //!
    //! \brief  Get the height of tiles merged picture
    //!
    //! \return uint32_t
    //!         the height of tiles merged picture
    //!
    uint32_t GetPackedPicHeight();

    //!
    //! \brief  Get the tiles arrangement information in tiles
    //!         merged picture
    //!
    //! \return TileArrangement*
    //!         the pointer to the tiles arrangement information
    //!
    TileArrangement* GetMergedTilesArrange();

protected:
    void                                    *m_pluginHdl;          //!< pointer to OMAF packing plugin handle
    RegionWisePackingGeneratorBase          *m_rwpkGen;            //!< pointer to detailed RWPK generator class instance corresponding to selected plugin
};

VCD_NS_END;
#endif /* _REGIONWISEPACKINGGENERATOR_H_ */
