document.querySelector(".menuTitle").addEventListener("click", function () {
    if (document.getElementById("overlay").style.visibility == 'visible')
        document.getElementById("overlay").style.visibility = 'hidden';
    else {
        document.getElementById("overlay").style.visibility = 'visible';
    }

})