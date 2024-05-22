<?php
require 'db-initializer.php'; // Include your connection script

try {
    $sql = "SELECT * FROM ENTITY_ACCOUNTS";
    $stmt = $pdo->query($sql);
    
    echo '<table border="1">';
    echo '<tr><th>ID</th><th>Username</th><th>Wins</th></tr>';

    while ($row = $stmt->fetch()) {
        echo '<tr>';
        echo '<td>' . $row['UserID'] . '</td>';
        echo '<td>' . $row['Username'] . '</td>';
        echo '<td>' . $row['Password'] . '</td>';
        echo '<td>' . $row['isAdmin'] . '</td>';
        echo '</tr>';
    }

    echo '</table>';
} catch (\PDOException $e) {
    echo "Error: " . $e->getMessage();
}

