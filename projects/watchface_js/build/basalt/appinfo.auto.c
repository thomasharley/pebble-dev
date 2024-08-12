#include "pebble_process_info.h"
#include "src/resource_ids.auto.h"

const PebbleProcessInfo __pbl_app_info __attribute__ ((section (".pbl_header"))) = {
  .header = "PBLAPP",
  .struct_version = { PROCESS_INFO_CURRENT_STRUCT_VERSION_MAJOR, PROCESS_INFO_CURRENT_STRUCT_VERSION_MINOR },
  .sdk_version = { PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR, PROCESS_INFO_CURRENT_SDK_VERSION_MINOR },
  .process_version = { 1, 0 },
  .load_size = 0xb6b6,
  .offset = 0xb6b6b6b6,
  .crc = 0xb6b6b6b6,
  .name = "WatchfaceJS",
  .company = "Thomas Harley",
  .icon_resource_id = DEFAULT_MENU_ICON,
  .sym_table_addr = 0xA7A7A7A7,
  .flags = PROCESS_INFO_WATCH_FACE | PROCESS_INFO_ROCKY_APP | PROCESS_INFO_PLATFORM_BASALT,
  .num_reloc_entries = 0xdeadcafe,
  .uuid = { 0x68, 0x7D, 0x55, 0xFE, 0x26, 0x9C, 0x47, 0x26, 0x96, 0xED, 0xAB, 0x8C, 0x01, 0xFF, 0x05, 0x5A },
  .virtual_size = 0xb6b6
};
