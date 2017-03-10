<table>
    <tr class = "top_row">
        <td>Method</td>
        <td>Stock</td>
        <td>Shares</td>
        <td>Price</td>
        <td>Date/Time</td>
    </tr>
   <?php foreach ($rows as $row): ?>

    <tr>
        <td><?= $row["method"] ?></td>
        <td><?= $row["symbol"] ?></td>
        <td><?= $row["num_shares"] ?></td>
        <td><?= $row["price"] ?></td>
        <td><?= $row["datetime"] ?></td>
    </tr>

    <?php endforeach ?>
    
    <tr></tr>
    <tr class = "bottom_row">
        <td colspan = "4">Current Balance</td>
        <td><?php print($cash); ?></td>
    </tr>
</table>