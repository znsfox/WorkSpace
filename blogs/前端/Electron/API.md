### ipcMain:

communicate asynchronously from the Main process to renderer processes.



The `ipcMain` module is an Event Emitter. When used in the Main process, it handles asynchronous and synchronous message from the renderer process(web page), 

Message sent from the renderer will emitted to this module.



Sending Message:

