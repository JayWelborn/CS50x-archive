<?php

        // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        // validate submission
        if (empty($_POST["stock"]))
        {
            apologize("You must provide a stock symbol.");
        }
       
       // set local variables
       $stock = strtoupper($_POST["stock"]);
       $stock = lookup($stock);
       $shares = $_POST["shares"];
       
       if (empty($_POST["shares"]))
       {
           apologize("You must provide a number of shares to buy.");
       }
       
       
       // return error if stock symbol invalid
       if ($stock === false)
       {
           apologize("Stock Symbol lookup failed.");
       }
       
       else
       {
            // unpack arrays for easier manipulation
            $symbol = $stock["symbol"];
            $name = $stock["name"];
            $price = round($stock["price"], 2);
            $id = $_SESSION["id"];
            $date = date('d M Y, H:i:s');
            
            // get cash for logged in user from database
            $row = CS50::query("SELECT cash FROM users WHERE id = ?", $id);
            if ($row !== false)
            {
                $cash = $row[0]["cash"];
            }
            else
            {
                apologize("Cannot find user's cash info.");
            }
            
            $row = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", 
                                $id, $symbol);
            
            // if user does not already own shares, create table row with 0 for number of shares
            if ($row == false)
            {
                CS50::query("INSERT INTO portfolio (user_id, symbol, shares) 
                             VALUES($id, '$symbol', 0)");
                $user_shares = 0;
            }
            
            // if user does own shares, retrieve # of shares from database
            else
            {
                $user_shares = $row[0]["shares"];
            }
            
            // check to make sure user has enough shares to sell
            if ($cash - $price * $shares < 0)
            {
                apologize("You don't have enough money to buy that stock.");
            }
            
            // add shares to current user-owned value, subtract price from user cash, write new line in history
            else
            {
                $cash -= $price;
                $user_shares += $shares;
                
                CS50::query("UPDATE portfolio SET shares = ? 
                             WHERE user_id = ? AND symbol = ?", 
                             $user_shares, $id, $symbol);
                             
                CS50::query("UPDATE users SET cash = ? 
                             WHERE id = ?", 
                             $cash, $id);
                
                CS50::query("INSERT INTO history (user_id, method, symbol, num_shares, price, datetime)
                                 VALUES ($id, 'Bought', '$symbol', $shares, $price, '$date')");
                
                // render page showing successful results of selling stock
                render("buy_success.php", ["shares" => $shares, "user_shares" => $user_shares, 
                                            "cash" => $cash, "title" => "Sell", "symbol" => $symbol]);
            }

       }
       
    }

?>