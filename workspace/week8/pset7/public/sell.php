<?php

        // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("sell_form.php", ["title" => "Sell"]);
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
           apologize("You must provide a number of shares to sell.");
       }
       
       
       // return error if stock symbol invalid
       if ($stock === false)
       {
           apologize("Stock Symbol Invalid");
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
                apologize("SQL query for user cash failed.");
            }
            
            // get number of shares currently owned by user
            $row = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $id, $symbol);
            if ($row !== false)
            {
                $user_shares = $row[0]["shares"];
            }
            else
            {
                apologize("SQL query for user shares failed");
            }
            
            // check to make sure user has enough shares to sell
            if ($user_shares - $shares < 0)
            {
                apologize("You don't own that many shares of that stock");
            }
            
            // subtract shares from current user-owned value, add price to user cash, write new values to database
            else
            {
                $cash += $price;
                $user_shares -= $shares;
                
                // add cash to user table
                CS50::query("UPDATE users SET cash = ? 
                             WHERE id = ?", 
                             $cash, $id);
                
                // delete row if user sold last shares
                if ($user_shares === 0)
                {
                    CS50::query("DELETE FROM portfolio
                                 WHERE user_id = ? AND symbol = ?",
                                 $id, $symbol);
                    
                    // track sale in history             
                    CS50::query("INSERT INTO history (user_id, method, symbol, num_shares, price, datetime)
                                 VALUES ($id, 'sell', '$symbol', $shares, $price, '$date')");
                }
                
                // else update row with new values
                else
                {
                    CS50::query("UPDATE portfolio SET shares = ? 
                                 WHERE user_id = ? AND symbol = ?", 
                                 $user_shares, $id, $symbol);
                     
                    // track sale in history          
                    CS50::query("INSERT INTO history (user_id, method, symbol, num_shares, price, datetime)
                                 VALUES ($id, 'Sold', '$symbol', $shares, $price, '$date')");
                }
                // render page showing successful results of selling stock
                render("sell_success.php", ["shares" => $shares, "user_shares" => $user_shares, 
                                            "cash" => $cash, "title" => "Sell", "symbol" => $symbol]);
            }

       }
       
    }

?>