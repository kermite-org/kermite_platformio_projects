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
	cmd /c mklink /d lib\KermiteCore_Arduino ..\..\..\KermiteCore_Arduino

symlink_win_remove:
	cmd /c rmdir lib\KermiteCore_Arduino

symlink_mac_create:
	ln -snF ../../KermiteCore_Arduino lib/KermiteCore_Arduino

symlink_mac_remove:
	unlink lib/KermiteCore_Arduino
