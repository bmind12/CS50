<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        if ($rows == false)
        {
            apologize("You have nothing to sell.");
        }
        else
        {
            foreach($rows as $row)
            {
                $stock = lookup($row["symbol"]);
                if ($stock !== false)
                {
                    $stocks[] = ["symbol" => $row["symbol"]];
                }
            }
        }
        
        // render form
        render("sell_form.php", ["title" => "Sell", "stocks" => $stocks]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    elseif ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (isset($_POST["symbol"]) == false)
        {
            apologize("You must select a stock to sell.");
        }
        else
        {
            $stock = lookup($_POST["symbol"]);
            if ($stock === false)
            {
                apologize("Symbol is not valid.");
            }

            $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            $price = $stock["price"];
            
            foreach ($rows as $row)
            {
                $shares = $row["shares"];
            }
            
            $revenue = $shares * $price;
            
            CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $revenue, $_SESSION["id"]);
            CS50::query("INSERT INTO history (user_id, transaction, time, symbol, shares, price) VALUES (?, 'SELL', CURRENT_TIMESTAMP, ?, ?, ?)", $_SESSION["id"], $_POST["symbol"], $shares, $price);
            
            redirect("/");
        }
    }

?>