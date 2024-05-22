<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Frost - Login & Sign Up</title>
    <link rel="stylesheet" href="login.css">
</head>
<body>
    <?php include 'SignUp_Method.php' ?>
     <div class="container" id="login-container">
        <h2>Login</h2>
        <form method="post">
            <div class="form-group">
                <label for="Username">Username</label>
                <input type="text" id="Username" name="Username" required>
            </div>
            <div class="form-group">
                <label for="Password">Password</label>
                <input type="Password" id="Password" name="Password" required>
            </div>
            <button class="btn" type="submit" name="login">Login</button>
        </form>
        <div class="switch">
            <p>Don't have an account? <a href="#" onclick="switchToSignUp()">Sign Up</a></p>
        </div>
    </div>

    <div class="container" id="signup-container" style="display: none;">
        <h2>Sign Up</h2>
        <form method="post">
            <div class="form-group">
                <label for="Username">Username</label>
                <input type="text" id="Username" name="Username" required>
            </div>
            <div class="form-group">
                <label for="Password">Password</label>
                <input type="password" id="Password" name="Password" required>
            </div>
            <button class="btn" type="submit" name="signup">Sign Up</button>
        </form>
        <div class="switch">
            <p>Already have an account? <a href="#" onclick="switchToLogin()">Login</a></p>
        </div>
    </div>

    <script>
        function switchToSignUp() {
            document.getElementById('login-container').style.display = 'none';
            document.getElementById('signup-container').style.display = 'block';
        }

        function switchToLogin() {
            document.getElementById('signup-container').style.display = 'none';
            document.getElementById('login-container').style.display = 'block';
        }

        function login() {
            // Add login functionality here
            alert('Login functionality not implemented yet.');
        }

        function signUp() {
            // Add sign up functionality here
            alert('Sign Up functionality not implemented yet.');
        }
    </script>
</body>
</html>


