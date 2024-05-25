<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GHOST - Login & Sign Up</title>
    <link rel="stylesheet" href="login.css">
</head>
<body>
    
     <div class="container" id="login-container">
         <?php include 'SignUp_Method.php' ?>
        <img class = "img" src = "Logo.webp">
        <h2>Login</h2>
        <form id = "loginForm" method="post">
            <div class="form-group">
                <label for="Username">Username</label>
                <input type="text" id="Username" name="Username" required>
            </div>
            <div class="form-group">
                <label for="Password">Password</label>
                <input type="Password" id="Password" name="Password" required>
            </div>
            <button class="btn" id="pseudoLoginButton" type="button">Login</button>
            <button class="btn" type="submit" id="realLoginButton" name ="login" style="display: none">Login</button>
        </form>
        <div class="switch">
            <p>Don't have an account? <a href="#" onclick="switchToSignUp()">Sign Up</a></p>
        </div>
    </div>

    <div class="container" id="signup-container" style="display: none;">
        
        <img class = "img" src = "Logo.webp">
        <h2>Sign Up</h2>
        <form id = "signupForm" method="post">
            <div class="form-group">
                <label for="Username">Username</label>
                <input type="text" id="Username" name="Username" required>
            </div>
            <div class="form-group">
                <label for="Password">Password</label>
                <input type="password" id="Password" name="Password" required>
            </div>
            <button class="btn" id="pseudoSignupButton" type="button">Sign Up</button>
            <button class="btn" type="submit" id="realSignUpButton" name ="signup" style="display: none">Sign Up</button>
        </form>
        <div class="switch">
            <p>Already have an account? <a href="#" onclick="switchToLogin()">Login</a></p>
        </div>
    </div>
    
    <audio id="submitSound" src="A.mp3" preload="auto"></audio>

    <script>
        
            function playSoundAndSubmit(formId, realButtonId) {
                const submitSound = document.getElementById('submitSound');
                submitSound.play();

                submitSound.onended = function() {
                    document.getElementById(realButtonId).click();
                };
            }
            
            function handleEnterKey(event, formId, pseudoButtonId) {
                if (event.key === 'Enter') {
                    const form = document.getElementById(formId);
                    const inputs = form.querySelectorAll('input[required]');
                    let allFilled = true;

                    inputs.forEach(input => {
                        if (!input.value) {
                            allFilled = false;
                        }
                    });

                    if (allFilled) {
                        event.preventDefault();
                        document.getElementById(pseudoButtonId).click();
                    }
                }
            }

            document.getElementById('pseudoLoginButton').addEventListener('click', function() {
                playSoundAndSubmit('loginForm', 'realLoginButton');
            });

            document.getElementById('pseudoSignupButton').addEventListener('click', function() {
                playSoundAndSubmit('signupForm', 'realSignUpButton');
            });
            
            document.getElementById('loginForm').addEventListener('keydown', function(event) {
                handleEnterKey(event, 'loginForm', 'pseudoLoginButton');
            });

            document.getElementById('signupForm').addEventListener('keydown', function(event) {
                handleEnterKey(event, 'signupForm', 'pseudoSignupButton');
            });
        
        
        function switchToSignUp() {
            document.getElementById('login-container').style.display = 'none';
            document.getElementById('signup-container').style.display = 'block';
        }

        function switchToLogin() {
            document.getElementById('signup-container').style.display = 'none';
            document.getElementById('login-container').style.display = 'block';
        }   
        
        
    </script>
</body>
</html>


