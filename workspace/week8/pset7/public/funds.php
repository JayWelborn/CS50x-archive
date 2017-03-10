<?php

    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("funds_form.php", ["title" => "Funds"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        // get info from form
        $cash = $_POST["cash"];
        $id = $_SESSION["id"];
        $date = date('d M Y, H:i:s');
        
        // error checking
        if(empty($cash))
        {
            apologize("Did not enter cash amount");
        }
        
        // get cash for logged in user from database
        $row = CS50::query("SELECT cash FROM users 
                            WHERE id = ?", $id);
        if ($row !== false)
        {
            $user_cash = $row[0]["cash"];
        }
        else
        {
            apologize("Cannot find user's cash info.");
        }
        
        // add input total to cash total and write it to database
        $user_cash += $cash;
        CS50::query("UPDATE users SET cash = ? 
                     WHERE id = ?", $user_cash, $id);
                     
        // update history
        CS50::query("INSERT INTO history (user_id, method, symbol, num_shares, price, datetime)
                                 VALUES ($id, 'Add Funds', '----', '----', $cash, '$date')");
                     
        render("funds_add.php", ["user_cash" => $user_cash, "cash" => $cash, "title" => "Add Funds"]);
    }
    
?>