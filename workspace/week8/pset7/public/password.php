<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("password_form.php", ["title" => "Change Password"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // ensure user typed password
        if (empty($_POST["password"]))
        {
            apologize("You must provide your current password.");
        }
        
        // ensure user typed new password
        else if (empty($_POST["new_password"]))
        {
            apologize("You must provide a new password.");
        }
        
        // ensure user typed new confirmation
        else if (empty($_POST["new_confirmation"]))
        {
            apologize("You must confirm your new password.");
        }
        
        // ensure new password and confirmation match
        else if ($_POST["new_password"] !== $_POST["new_confirmation"])
        {
            apologize("New passwords do not match.");
        }
        
        // query database for user
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);

        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];
        }

        // ensure user typed correct password
        if (!password_verify($_POST["password"], $row["hash"]))
        {
            apologize("Incorrect Current Password");
        }
        
        // update password
        $result = CS50::query("UPDATE users SET hash = ? WHERE id = ?", 
                     password_hash($_POST["new_password"], PASSWORD_DEFAULT), 
                     $_SESSION["id"]);
                     
        if ($result === 0)
        {
            apologize("Registration error");
        }
        else
        {
            render('password_success.php', ['title' => 'Change Password']);
        }
    }
    
?>