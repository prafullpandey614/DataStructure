 function handleRecordButton(event){
        recordButton = event;
        
        msb = document.querySelector("#user_message")
        loader = document.getElementById("loader");
        container = document.getElementById("container");

        if (event.textContent == "Record") {
          console.log('start');
          startRecording();
        } else {
          console.log('end');
         stopRecording();  

        } 
      }
