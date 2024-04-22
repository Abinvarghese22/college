import java.awt.*;
import java.awt.event.*;

public class MaximumFinder extends Frame implements ActionListener {
    private TextField num1Field, num2Field, num3Field;
    private Label resultLabel;

    public MaximumFinder() {
        setTitle("Maximum Finder");
        setSize(300, 200);
        setLayout(new GridLayout(5, 2));

        Label num1Label = new Label("Enter number 1:");
        num1Field = new TextField(10);
        add(num1Label);
        add(num1Field);

        Label num2Label = new Label("Enter number 2:");
        num2Field = new TextField(10);
        add(num2Label);
        add(num2Field);

        Label num3Label = new Label("Enter number 3:");
        num3Field = new TextField(10);
        add(num3Label);
        add(num3Field);

        Button calculateButton = new Button("Calculate");
        calculateButton.addActionListener(this);
        add(calculateButton);

        resultLabel = new Label("");
        add(resultLabel);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void actionPerformed(ActionEvent e) {
        int num1 = Integer.parseInt(num1Field.getText());
        int num2 = Integer.parseInt(num2Field.getText());
        int num3 = Integer.parseInt(num3Field.getText());

        int max = Math.max(num1, Math.max(num2, num3));
        resultLabel.setText("Maximum number is: " + max);
    }

    public static void main(String[] args) {
        MaximumFinder maxFinder = new MaximumFinder();
        maxFinder.setVisible(true);
    }
}

