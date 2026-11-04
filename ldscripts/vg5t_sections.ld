SECTIONS
{
    .app_start ORIGIN(REGION_TEXT) : { KEEP(*(.app_start)) }
    .settings  0x0000F000 : { KEEP(*(.settings)) }
}

_app_start_addr = ADDR(.app_start);
_settings_addr = ADDR(.settings);
ASSERT(LOADADDR(.data) + SIZEOF(.data) <= _settings_addr,
       "Application overlaps the settings area")
