<?php
include 'db_connect.php';

$username = $_POST['username'];
$email = $_POST['email'];
$password = password_hash($_POST['password'], PASSWORD_DEFAULT);

$sql = "INSERT INTO users (username, email, password) VALUES ('$username', '$email', '$password')";

if (mysqli_query($conn, $sql)) {
    echo "Account created! <a href='login.html'>Login here</a>";
} else {
    echo "Error: " . mysqli_error($conn);
}

mysqli_close($conn);
?>