<?php
session_start();


require 'db-initializer.php';

// Handle user deletion and addition
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['delete'])) {
        $userID = $_POST['userID'];
        $sql = "DELETE FROM entity_accounts WHERE UserID = ?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$userID]);
    } elseif (isset($_POST['addUser'])) {
        $username = $_POST['username'];
        $password = password_hash($_POST['password'], PASSWORD_BCRYPT);
        $isAdmin = isset($_POST['isAdmin']) ? 1 : 0;
        $sql = "INSERT INTO entity_accounts (Username, Password, isAdmin) VALUES (?, ?, ?)";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$username, $password, $isAdmin]);
    } elseif (isset($_POST['deleteItem'])) {
        $itemSKU = $_POST['itemSKU'];
        $sql = "DELETE FROM items WHERE ItemSKU = ?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$itemSKU]);
    } elseif (isset($_POST['addItem'])) {
        $name = $_POST['name'];
        $description = $_POST['description'];
        $price = $_POST['price'];
        $image = $_POST['image'];
        $sql = "INSERT INTO items (Name, Description, price, Image) VALUES (?, ?, ?, ?)";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$name, $description, $price ,$image]);
    }
}

// Fetch users and items from the database
try {
    $sql = "SELECT * FROM entity_accounts";
    $users = $pdo->query($sql);
    $sql = "SELECT * FROM items";
    $items = $pdo->query($sql);
} catch (\PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin User Menu</title>
    <link rel="stylesheet" href="admin.css">
    <style>
        .section {
            display: none;
        }
        .section.active {
            display: block;
        }
    </style>
</head>
<body>
    <header class="navbar">
        <div class="container">
            <a href = "IndexAdmin.php">
                <img class="logo" src="Logo.webp" >
            </a>
            <h1>Admin Activities</h1>
        </div>
        <div class="user">
            <span class="username"><a href="index.php"><?php echo htmlspecialchars($_SESSION['username']); ?></a></span>
        </div>
    </header>

    <main>
        <h2>Admin User Menu</h2>
        <nav>
            <button id="showUsersBtn">Users</button>
            <button id="showItemsBtn">Items</button>
        </nav>

        <section id="usersSection" class="section active">
            <h3>All Users</h3>
            <table border="1">
                <tr><th>ID</th><th>Username</th><th>Admin</th><th>Action</th></tr>
                <?php while ($row = $users->fetch()) { ?>
                    <tr>
                        <td><?php echo $row['UserID']; ?></td>
                        <td><?php echo htmlspecialchars($row['Username']); ?></td>
                        <td><?php echo $row['isAdmin'] ? 'Yes' : 'No'; ?></td>
                        <td>
                            <form method="post" style="display:inline;">
                                <input type="hidden" name="userID" value="<?php echo $row['UserID']; ?>">
                                <button type="submit" name="delete" onclick="return confirm('Are you sure you want to delete this user?')">Delete</button>
                            </form>
                        </td>
                    </tr>
                <?php } ?>
            </table>
            
            <h3>Add New User</h3>
            <form method="post">
                <label for="username">Username:</label>
                <input type="text" id="username" name="username" required>
                <label for="password">Password:</label>
                <input type="password" id="password" name="password" required>
                <label for="isAdmin">Admin:</label>
                <input type="checkbox" id="isAdmin" name="isAdmin">
                <button type="submit" name="addUser">Add User</button>
            </form>
        </section>

        <section id="itemsSection" class="section">
            <h3>All Items</h3>
            <table border="1">
                <tr><th>SKU</th><th>Name</th><th>Description</th><th>Price</th><th>Image</th><th>Action</th></tr>
                <?php while ($row = $items->fetch()) { ?>
                    <tr>
                        <td><?php echo $row['ItemSKU']; ?></td>
                        <td><?php echo htmlspecialchars($row['Name']); ?></td>
                        <td><?php echo htmlspecialchars($row['Description']); ?></td>
                        <td><?php echo htmlspecialchars($row['Price']); ?></td>
                        <td><?php echo htmlspecialchars($row['image']); ?></td>
                        <td>
                            <form method="post" style="display:inline;">
                                <input type="hidden" name="itemSKU" value="<?php echo $row['ItemSKU']; ?>">
                                <button type="submit" name="deleteItem" onclick="return confirm('Are you sure you want to delete this item?')">Delete</button>
                            </form>
                        </td>
                    </tr>
                <?php } ?>
            </table>

            <h3>Add New Item</h3>
            <form method="post">
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required>
                <label for="description">Description:</label>
                <textarea id="description" name="description" required></textarea>
                <label for="price">Price:</label>
                <input type="text" id="price" name="price" required>
                <label for="image">Image Path:</label>
                <input type="text" id="image" name="image" required>
                <button type="submit" name="addItem">Add Item</button>
            </form>
        </section>
    </main>

    <footer class="footer">
        <p>&copy; 2024 GHOST. All rights reserved.</p>
    </footer>

    <script>
        document.getElementById('showUsersBtn').addEventListener('click', function() {
            document.getElementById('usersSection').classList.add('active');
            document.getElementById('itemsSection').classList.remove('active');
        });

        document.getElementById('showItemsBtn').addEventListener('click', function() {
            document.getElementById('usersSection').classList.remove('active');
            document.getElementById('itemsSection').classList.add('active');
        });
    </script>
</body>
</html>
