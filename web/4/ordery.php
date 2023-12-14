<?php
$db = @mysqli_connect( 'localhost' , 'root' , '', 'kmz' ) or die ( 'Ошибка соединения с БД');
if (! $db ) die ( mysqli_connect_error());
mysqli_set_charset( $db, "utf8" ) or die ( 'Не установлена кодировка' );

if(isset($_POST["user"]) && isset($_POST["email"]) && isset($_POST["phone"]) && isset($_POST["comment"]) && isset($_POST["company"])) 
{   
    
    $name = mysqli_real_escape_string( $db, $_POST['user'] );
    $email = mysqli_real_escape_string( $db, $_POST['email'] );
    $phone = mysqli_real_escape_string( $db, $_POST['phone'] );
    if(isset($_POST["loader"])) $loader = 1;
    $company = mysqli_real_escape_string($db, $_POST["company"][0]);
    $comment = mysqli_real_escape_string( $db, $_POST['comment'] );
    $insert = "INSERT INTO orders (name, email, phone, loader, company, comment) VALUES ('$name', '$email', '$phone', '$loader', '$company', '$comment')";
    $res_insert = mysqli_query($db, $insert);

    if ($res_insert) echo 'Заказ передан в обработку.';
    else 'Ошибка отправки заказа.';
    echo mysqli_error($db);
}
?>

<html>

<head>
    <meta windows=1251>
    <title>КМЗ - Главная</title>
    <link rel="stylesheet" type="text/css" href="st.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:ital,wght@0,400;0,800;1,300&display=swap"
        rel="stylesheet">
</head>

<body>
    <header class="site_header">
        <img class="logo"> </img>
        <a>КМЗ</a>

        <nav class="top_menu">
            <li><a href="index.html"> Главная </a></li>
            <li><a href="#"> Заказать </a></li>
            <li><a href="about.html"> О нас </a></li>
            <li><a href="contact.html"> Контакты </a></li>
        </nav>
    </header>

    <div id="main_wrapper">

        <aside>
            <nav class="left_menu">
                <li><a href="engines.html"> Двигатели </a></li>
                <li><a href="transmissions.html"> Трансмиссии </a></li>
                <li><a href="clutches.html"> Диски сцепления </a></li>
                <li><a href="mh.html"> Маховики </a></li>
            </nav>
        </aside>

        <section>
            <article class="infoblock">
                <header class="infoblock_head"> Заполните форму и мы с вами свяжемся! 
                </header>
                <img class="cargo"></img>

                Рассчет стоимости доставки запчастей происходит в течение часа.
                <br /> <b>Внимание! <br />
                Заказ регистрируется только после согласования с оператором по контактному телефону.</b>
                <br />

                <h2>Ваши контакты</h2>
                <form action="ordery.php" method="POST">
                    <p>Имя:<br>
                        <input type="text" name="user" />
                    </p>
                    <p>E-mail<br>
                        <input type="text" name="email" />
                    </p>
                    <p>Телефон<br>
                        <input type="text" name="phone" />
                    </p>
                    <h1>Доставка</h1>
                    <p>Транспортная компания: <br>
                        <select name="company[]" size="4" multiple="multiple">
                            <option value="Деловые линии">Деловые линии</option>
                            <option value="Энергия">Энергия</option>
                            <option value="ПЭК">ПЭК</option>
                            <option value="Крастранс">Крастранс</option>
                        </select>
                    </p>


                    <input type="checkbox" name="loader" />Потребуются грузчики


                    <p>Комментарий: <br>
                        <textarea name="comment" maxlength="500"></textarea>
                    </p>
                    <input type="submit" value="Подтвердить">

                </form>
            </article>
        </section>
    </div>

    <div id="clearD"></div>

</body>

</html>