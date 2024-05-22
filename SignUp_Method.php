<?php
require 'db-initializer.php';

try {
    $pdo = new PDO($dsn, $user, $pass, $options);
    echo "<script>console.log('Connected successfully');</script>";

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        echo "<script>console.log('POST Data: " . json_encode($_POST) . "');</script>";

        if (isset($_POST['signup'])) {
            if (isset($_POST['Username']) && isset($_POST['Password'])) {
                $Username = $_POST['Username'];
                $optionsBcrypt = ['cost' => 10];
                $Password = password_hash($_POST['Password'], PASSWORD_BCRYPT, $optionsBcrypt);
                //$isAdmin = isset($_POST['isAdmin']) ? 1 : 0;

                $stmt = $pdo->prepare('INSERT INTO entity_accounts (Username, Password) VALUES (:Username, :Password)');
                $stmt->execute(['Username' => $Username, 'Password' => $Password]);

                echo "<script>console.log('Sign-up successful!');</script>";
            } else {
                echo "<script>console.log('Username or Password not set');</script>";
            }
        }

        if (isset($_POST['login'])) {
            if (isset($_POST['Username']) && isset($_POST['Password'])) {
                $Username = $_POST['Username'];
                $Password = $_POST['Password'];

                $stmt = $pdo->prepare('SELECT Password, isAdmin FROM entity_accounts WHERE Username = :Username');
                $stmt->execute(['Username' => $Username]);
                $user = $stmt->fetch();

                if ($user && password_verify($Password, $user['Password'])) {
                    echo "<script>console.log('Login successful!');</script>";
                    if ($user['isAdmin']) {
                        echo "<script>console.log('Welcome, Admin!');</script>";
                        header("Location: index.php");
                        exit;
                    } else {
                        echo "<script>console.log('Welcome, User!');</script>";
                        header("Location: index.php");
                        exit;
                    }
                } else {
                    echo "Invalid Username or Password";
                }
            } else {
                echo "<script>console.log('Username or Password not set');</script>";
            }
        }
    }
} catch (\PDOException $e) {
    echo "<script>console.log('".$e->getMessage()."');</script>";
}

