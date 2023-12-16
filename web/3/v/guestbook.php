<?php

	header("Content-type: text/html; charset=utf-8 ");
	error_reporting(-1);
	
	require_once 'connect.php';
	require_once 'funcs.php';
	
	if (! empty ($_POST )){
		save_mess();
		header ("Location: {$_SERVER['PHP_SELF']}");
		exit ;
	}

?>

<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="grigorevcss.css">
<title>Автомобили с пробегом</title>
</head>
<body>
<header class="top banner">Автомобили с пробегом</header>
<header class="site_header"> Автомобили с пробегом в г. Красноярске <nav class="top_menu"> <a href="sell.html">Продать авто</a>      <a href="company.html">О компании</a>      <a href="contacts.html">Контакты</a> </nav> </header>
<div id="main_wrapper">
	<aside> Каталог
		<nav class="left_menu"> <a href="audi.html">AUDI</a> <br><a href="bmw.html">BMW</a> <br><a href="honda.html">HONDA</a> <br><a href="merc.html">MERCEDES-BENZ</a> <br><a href="toyo.html">TOYOTA</a> <br><a href="lada.html">LADA</a>  </nav> </aside>
<section>
Основоной контент
<article class="infoblock"> <header class="infoblock_head"><font size="6"> Преимущества</font> </header> <img src="skidka.png" width="1400" height="250" align="center"/>  </article>
<article class="infoblock"> <header class="infoblock_head"><font size="6"> Как происходит обмен авто?</font></header> <img src="skidka2.png" width="1400" height="350" align="center"/> </article>

<article class="infoblock"> <header class="infoblock_head"><font size="6"> Оставить заявку</font></header>
<form action="guestbook.php" method="post">
  <label for="name">Ваше имя:</label><br>	
  <input type="text" id="name" name="name" ><br>
  <label for="phone">Ваш номер телефона:</label><br>
  <input type="text" id="phone" name="phone" ><br>
  <label for="email">Ваша почта:</label><br>
  <input type="text" id="email" name="email"><br>
<p>Тип обмена <br> 
<input type="radio" name="eduform" value="ключ в ключ" />ключ в ключ <br>
<input type="radio" name="eduform" value="кредит" />кредит <br>
<input type="radio" name="eduform" value="наличные" />наличные <br>
  <label for="message">Сообщение:</label><br>
  <textarea name="message" id="message" rows="4" cols="50"></textarea><br>
  <input type="submit" value="Отправить">
</form> 
</article>

</section>
</div>
<div id="clearD"></div>
<footer> copyright </footer>
</body>
</html>