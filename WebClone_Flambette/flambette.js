const { LoopOnce } = require("three");

let x = 0;
let y = 0;
let mx = 0;
let my = 0;
let speed = 0.03;
let scrollTop = 0;
let candles_bottom, candles_middle, candles_top, 
    soap_bottom, soap_middle, soap_top, 
    spray_bottom, spary_middle, spray_top;

window.onload = function(){

    candles_bottom = document.getElementById('candles_bottom');
    candles_middle = document.getElementById('candles_middle');
    candles_top = document.getElementById('candles_top');

    soap_bottom = document.getElementById('soap_bottom');
    soap_middle = document.getElementById('soap_middle');
    soap_top = document.getElementById('soap_top');

    spray_bottom = document.getElementById('spray_bottom');
    spray_middle = document.getElementById('spray_middle');
    spray_top = document.getElementById('spray_top');

    window.addEventListener("scroll", function(event){
        var scroll = this.scrollY;

        candles_top.style.transform = "translateX(" + -scroll/10 + "px)";
        candles_middle.style.transform = "transformX(" + -scroll/10 + "px)";
        
        soap_top.style.transform = "translateX(" + -scroll/10 + "px)";
        soap_middle.style.transform = "translateX(" + -scroll/10 + "px)";
    
        spray_top.style.transform = "translateX(" + -scroll/10 + "px)";
        spary_middle.style.transform = "translateX(" + -scroll/10 + "px)";

        window.addEventListener('resize', stageResize, false);
        window.addEventListener('mousemove', mouseMove, false);
        window,addEventListener('scroll', scrollFunc, false);

        stageResize();
        loop();
    })

    function scrollFunc(e){
        var scrollTop = document.documentElement.scrollTop;
    }
    
    function stageResize() {        //per를 위한 함수 (document랑 window height값)
        _documentHum = document.body.offsetHeight;
        _windowNum = window.outerHeight;
    }
    
    function mouseMove (e) {        //윈도우 width의 가운데 기준
        x = (e.clientX - window.innerHeight / 2);
        y = (e.clientY - window.innerHeight / 2);
    }
}