<?php
$db = @mysqli_connect( 'localhost' , 'root' , '', 'kmz' ) or die ( 'Ошибка соединения с БД');
if (! $db ) die ( mysqli_connect_error());
mysqli_set_charset( $db, "utf8" ) or die ( 'Не установлена кодировка' );

$insert = "INSERT INTO orders (name) VALUES ('Ольга')";
$res_insert = mysqli_query($db, $insert);

if ($res_insert) echo 'OK';
else 'error';
echo mysqli_error($db);
?>