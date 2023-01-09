function isDeviceRawHidInterface(device) {
  return device.collections.some(
    (col) => col.usagePage === 0xff00 && col.usage === 0x01
  );
}

function delayMs(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function start() {
  const devices = (
    await navigator.hid.requestDevice({
      filters: [
        { vendorId: 0xf055, productId: 0xa579 },
        { vendorId: 0xf055, productId: 0xa57a },
      ],
    })
  ).filter(isDeviceRawHidInterface);

  console.log({ devices });

  const device = devices[0];
  if (device) {
    console.log(device);
    console.log(device.productName);
    console.log({
      vid: device.vendorId.toString(16),
      pid: device.productId.toString(16),
    });

    await device.open();

    device.addEventListener("inputreport", (e) => {
      const rcvBytes = [...new Uint8Array(e.data.buffer)];
      // console.log({ e });
      console.log({ rcvBytes });
    });

    device.addEventListener("disconnect", () => {
      console.log("closed");
    });

    console.log("device opened");

    window.addEventListener("mousedown", async (e) => {
      if (e.button === 2) {
        console.log("send");
        const reportId = 0;
        const bytes = new Uint8Array(64);
        bytes[0] = 0xf2;
        // device.sendReport(reportId, bytes);
        try {
          await device.sendReport(reportId, bytes);
        } catch (err) {
          console.error(err);
          console.log({ err });
        }
      }
    });
  }
}

window.addEventListener("click", start, { once: true });
window.addEventListener("contextmenu", (e) => e.preventDefault());
