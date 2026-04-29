<?php
session_start();
include 'db_connect.php';

$email = $_POST['email'];
$password = $_POST['password'];

$sql = "SELECT * FROM users WHERE email = '$email'";
$result = mysqli_query($conn, $sql);
$user = mysqli_fetch_assoc($result);

if ($user && password_verify($password, $user['password'])) {
    $_SESSION['username'] = $user['username'];
    echo "<script>window.location.href = 'http://localhost:8888/kipo/index.html';</script>";
    exit();
} else {
    echo "Invalid email or password. <a href='login.html'>Try again</a>";
}

mysqli_close($conn);
?>