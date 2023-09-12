 function handleRecordButton(event){
        recordButton = event;
        errorMsgElement = document.querySelector("#errorMsg1");
        recordedVideo = document.querySelector("#recorded1")
        retakeButton=document.querySelector("#retake")
        recordedVideo1=document.querySelector("#gum1")
        retakeButton = document.querySelector("#retake")
        playButton = document.querySelector("#play1")
        nextButton = document.querySelector("#nextid")
        accessToken = localStorage.getItem("accessToken")
        downloadButton = document.querySelector("#download1")
        questionNumbers = document.querySelector("h2.w3-wide")
        aboutQuestion = document.querySelector("p.w3-opacity");
        tapToStartMessage = document.querySelector("h5");
        questions= document.querySelector("p.w3-justify");
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
