ins

<?php
$servername="localhost";
$username="root";
$password="";
$dbname="mca";

$con=mysqli_connect($servername,$username,$password,$dbname);
if($con){
	echo "succes <br>";   
}else{
    die("not");
}

$fname=$_POST["fname"];
$lname=$_POST["lname"];
$email=$_POST["email"];
$phone=$_POST["phone"];

$sql = "INSERT INTO stu (fname,lname,email,phone)VALUES('$fname','$lname','$email','$phone')";

if(mysqli_query($con,$sql)){
    echo "succes";
}else{
    echo "fail";
}
?>


disp


<?php
$servername="localhost";
$username="root";
$password="";
$dbname="mca";

$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM stu";
$result = $conn->query($sql);

{
    while($row = $result->fetch_assoc()) {
        echo "
        <table>
        <tr>
    <td>".$row['fname']."</td>
    <td>".$row['lname']."</td>
    <td>".$row['email']."</td>
    <td>".$row['phone']."</td>
    </tr>
    </table>
    ";


    }
} 
?>



del

<?php
$servername="localhost";
$username="root";
$password="";
$dbname="mca";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// SQL to delete a record
$sql = "DELETE FROM std WHERE id=3";

if ($conn->query($sql) === TRUE) {
  echo "Record deleted successfully";
} else {
  echo "Error deleting record: " . $conn->error;
}

$conn->close();
?>



upd

<?php
$servername="localhost";
$username="root";
$password="";
$dbname="mca";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// SQL to update a record
$sql = "UPDATE stu SET phone='5647382828' WHERE id=3";

if ($conn->query($sql) === TRUE) {
  echo "Record updated successfully";
} else {
  echo "Error updating record: " . $conn->error;
}

$conn->close();
?>



val

<!DOCTYPE html>
<html>
<head>
  <title>Form Validation</title>
  <script>
    function validateForm() {
      var name = document.getElementById('name').value;
      var password = document.getElementById('password').value;
      var email = document.getElementById('email').value;
      var phone = document.getElementById('phone').value;

      var nameRegex = /^[a-zA-Z\s]+$/;
      var emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
      var passwordRegex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}$/;
      var phoneRegex = /^\d{10}$/;

      if (!name.match(nameRegex)) {
        alert('Please enter a valid name.');
        return false;
      }

      if (!password.match(passwordRegex)) {
        alert('Password must contain at least one lowercase letter, one uppercase letter, one numeric digit, and be at least 6 characters long.');
        return false;
      }

      if (!email.match(emailRegex)) {
        alert('Please enter a valid email address.');
        return false;
      }

      if (!phone.match(phoneRegex)) {
        alert('Please enter a valid 10-digit phone number.');
        return false;
      }

      return true;
    }
  </script>
</head>
<body style="text-align: center;">
    <div style="background-color: aqua; color:red">
  <form onsubmit="return validateForm()">
    <input type="text" id="name" placeholder="Name">
    <br>
    <input type="password" id="password" placeholder="Password">
    <br>
    <input type="text" id="email" placeholder="Email">
    <br>
    <input type="text" id="phone" placeholder="Phone">
    <br>
    <input type="submit" value="Submit">
  </form>
  </div>
</body>
</html>
