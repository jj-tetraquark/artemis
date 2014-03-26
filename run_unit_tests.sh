#!/bin/sh

find -iname test_ut -exec {} --report_level=short --show_progress=yes --color_output=yes \;
