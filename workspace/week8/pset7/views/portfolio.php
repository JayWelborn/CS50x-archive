<table>
    <tr class = "top_row">
        <td>Symbol</td>
        <td>Shares</td>
        <td>Price</td>
    </tr>
   <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= $position["price"] ?></td>
    </tr>

    <?php endforeach ?>
   
    <tr class = "bottom_row">
        <td>Cash</td>
        <td></td>
        <td><?php print($cash); ?></td>
    </tr>
</table>