build:
	pio run

flash:
	pio run --target upload

clean:
	pio run --target clean

monitor:
	pio run --target monitor

debug: flash monitor

# create library symlink for development
symlink_win_create:
	cmd /c mklink /d lib\kermite_core_arduino\src ..\..\..\..\KermiteCore_Arduino\src

symlink_win_remove:
	cmd /c rmdir lib\kermite_core_arduino\src

symlink_mac_create:
	ln -snF ../../../../kermite_core_arduino/src lib/KermiteCore_Arduino/src

symlink_mac_remove:
	unlink lib/kermite_core_arduino/src

