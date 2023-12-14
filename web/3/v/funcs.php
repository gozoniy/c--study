<?php

function save_mess(){
	global $db;
	$name = mysqli_real_escape_string( $db, $_POST['name'] );
    	$phone = mysqli_real_escape_string( $db, $_POST['phone'] );
    	$email = mysqli_real_escape_string( $db, $_POST['email'] );
    	$eduform = mysqli_real_escape_string( $db, $_POST['eduform'] );
    	$message = mysqli_real_escape_string( $db, $_POST['message'] );
	$query = "INSERT INTO lab3 (name, phone, email, eduform, message) VALUES ('$name', '$phone', '$email', '$eduform', '$message')";
	mysqli_query($db, $query);
}

?>