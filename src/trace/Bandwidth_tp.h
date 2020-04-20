#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER bandwidth_tp_provider

#if !defined(_TRACEPOINT_BANDWIDTH_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_BANDWIDTH_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    bandwidth_tp_provider,
    initial_viewport_info,
    TP_ARGS(
        int,         viewport_init_width,
        int,         viewport_init_height,
        float,       viewport_init_pitch,
        float,       viewport_init_yaw,
        float,       viewport_horizontal_fov,
        float,       viewport_vertical_fov,
        const char*, projection_type
    ),

    TP_FIELDS(
        ctf_integer(int, viewport_set_width, viewport_init_width)
        ctf_integer(int, viewport_set_height, viewport_init_height)
        ctf_float(float, viewport_set_pitch, viewport_init_pitch)
        ctf_float(float, viewport_set_yaw, viewport_init_yaw)
        ctf_float(float, horizontal_fov_angle, viewport_horizontal_fov)
        ctf_float(float, vertical_fov_angle, viewport_vertical_fov)
        ctf_string(projection_type_field, projection_type)
    )
)

TRACEPOINT_EVENT(
    bandwidth_tp_provider,
    tiles_selection_redundancy,
    TP_ARGS(
        int, viewport_net_width,
        int, viewport_net_height,
        int, viewport_tiled_width,
        int, viewport_tiled_height,
        int, selected_tile_rows,
        int, selected_tile_cols
    ),

    TP_FIELDS(
        ctf_integer(int, net_width_field, viewport_net_width)
        ctf_integer(int, net_height_field, viewport_net_height)
        ctf_integer(int, tiled_width_field, viewport_tiled_width)
        ctf_integer(int, tiled_height_field, viewport_tiled_height)
        ctf_integer(int, tile_rows_field, selected_tile_rows)
        ctf_integer(int, tile_cols_field, selected_tile_cols)
    )
)

TRACEPOINT_EVENT(
    bandwidth_tp_provider,
    encoded_frame_size,
    TP_ARGS(
        char*, resolution,
        char*, tile_split,
        int,   frame_index,
        int,   frame_size
    ),

    TP_FIELDS(
        ctf_string(resolution_field, resolution)
        ctf_string(tile_split_field, tile_split)
        ctf_integer(int, frame_index_field, frame_index)
        ctf_integer(int, frame_size_field, frame_size)
    )
)

TRACEPOINT_EVENT(
    bandwidth_tp_provider,
    packed_segment_size,
    TP_ARGS(
        int,         track_index,
        const char*, track_type,
        int,         segment_index,
        int,         segment_size
    ),

    TP_FIELDS(
        ctf_integer(int, track_index_field, track_index)
        ctf_string(track_type_field, track_type)
        ctf_integer(int, segment_index_field, segment_index)
        ctf_integer(int, segment_size_field, segment_size)
    )
)

TRACEPOINT_EVENT(
    bandwidth_tp_provider,
    segmentation_info,
    TP_ARGS(
        const char*, dash_mode,
        int,         segment_duration,
        float,       frame_rate,
        int,         total_frames_num,
        int,         total_segments_num
    ),

    TP_FIELDS(
        ctf_string(dash_mode_field, dash_mode)
        ctf_integer(int, segment_duration_field, segment_duration)
        ctf_float(float, frame_rate_field, frame_rate)
        ctf_integer(int, total_frames_field, total_frames_num)
        ctf_integer(int, total_segments_field, total_segments_num)
    )
)

#endif /* _TRACEPOINT_BANDWIDTH_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./Bandwidth_tp.h"

#include <lttng/tracepoint-event.h>
