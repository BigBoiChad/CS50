document.addEventListener('DOMContentLoaded', function(){
    document.getElementById("basic-info").onclick = function () {
        location.href = "https://ide-4abb0aceb7654f43a68d659fa19c36a6-8080.cs50.ws/homepage/Basic%20Info.html";
    };
    document.getElementById("education").onclick = function () {
        location.href = "https://ide-4abb0aceb7654f43a68d659fa19c36a6-8080.cs50.ws/homepage/Education.html";
    };
    document.getElementById("interests").onclick = function () {
        location.href = "https://ide-4abb0aceb7654f43a68d659fa19c36a6-8080.cs50.ws/homepage/Interests.html";
    };
    document.getElementById("search").onclick = function () {
        alert("You Will Go To The Google Search Page");
        location.href = "https://www.google.com";
    };
    document.getElementById("skills").onclick = function () {
        location.href = "#about-skills";
    };
    document.getElementById("contact").onclick = function () {
        location.href = "#about-contact";
    };


    var close = document.getElementsByClassName("closebtn");
    var i;

    for (i = 0; i < close.length; i++) {
        close[i].onclick = function(){
        var div = this.parentElement;
        div.style.opacity = "0";
        setTimeout(function(){ div.style.display = "none"; }, 600);
        }
    }
});


