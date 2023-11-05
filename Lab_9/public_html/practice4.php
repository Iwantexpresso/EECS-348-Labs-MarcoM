
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

 $size = $_POST['size'];
 
 echo "<table border='1px solid black'> <tbody>" ;
 for ($x = 1; $x <= $size; $x++) {
    echo "<tr>";
    for ($y = 1; $y <= $size; $y++) {
         $out = $x*$y;
         echo" <td>".$out."</td>";
    
      } 
    echo "</tr>";
  } 
echo "</tbody> </table>";
}
?>

