function validate() {
    var p1 = document.getElementById("p1").value;
    var p2 = document.getElementById("p2").value;


    if (p1.length < 8) {
        alert("the lengt must be 8 or more letters")
    } else if (p2.length != p1.length) {
        alert("Passwords must be the same lenght")
    } else if (p1 != p2) {
        alert("Error: passwords must match")
    } else {
        alert("the password has passed the passthrough!")
    }
}
