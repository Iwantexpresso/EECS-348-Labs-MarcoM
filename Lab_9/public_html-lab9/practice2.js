function alert_paragraph_color() {
    var b_R = document.getElementById("border_R").value;
    var b_G = document.getElementById("border_G").value;
    var b_B = document.getElementById("border_B").value;
    var b_w = document.getElementById("border_width").value;

    var tag = document.getElementById("paragraph");
    tag.style.borderColor = `rgb(${b_R},${b_G},${b_B})`;
    tag.style.borderWidth = b_w
    
}d