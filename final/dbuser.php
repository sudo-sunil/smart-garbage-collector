<?php


require "connect.php";

if(!empty($_POST['id']) && !empty($_POST['password'])):
$id=$_POST["id"];
$password=$_POST["password"];
/*
$sql= "SELECT * from mango WHERE username='".$username."'AND password='".$password."'";

*/
$sql= $conn->prepare("SELECT * from stafflogin WHERE id=? AND password= ?");
$sql->bind_param('ss', $id,$password);
$sql->execute();
$result = $sql->get_result();
$message = '';
if($result->num_rows>0)
{
	session_start();

	$row=$result->fetch_assoc();
	$_SESSION['staff_name'] = $row['name'];
	$_SESSION['staff_id'] = $row['id'];
	$_SESSION['mentee'] = $row['mentee'];
	header("Location:stafflogin.php");
}	
else										//redirect to home page
{ 
$message = 'Incorrect username and password';
echo "<script type='text/javascript'> alert('$message');</script>";
include('stafflogin.php');
}
 
 endif;

?>
