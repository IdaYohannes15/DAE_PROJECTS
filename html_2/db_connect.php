<?php
$host = "localhost";
$user = "root";
$password = "root"; // MAMP default
$database = "kipo_db";
$port = 8889; // YOUR MAMP MySQL port

$conn = mysqli_connect($host, $user, $password, $database, $port);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>