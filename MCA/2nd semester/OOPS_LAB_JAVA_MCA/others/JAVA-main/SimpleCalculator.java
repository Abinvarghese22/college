import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator extends Frame implements ActionListener {
    private TextField displayField;
    private Button[] digitButtons;
    private Button[] operatorButtons;
    private Button clearButton;
    private Button equalsButton;
    private String currentInput;

    public SimpleCalculator() {
        setTitle("Simple Calculator");
        setSize(250, 300);
        setLayout(new BorderLayout());

        displayField = new TextField();
        add(displayField, BorderLayout.NORTH);

        Panel buttonPanel = new Panel(new GridLayout(4, 4));
        add(buttonPanel, BorderLayout.CENTER);

        digitButtons = new Button[10];
        for (int i = 0; i < 10; i++) {
            digitButtons[i] = new Button(String.valueOf(i));
            digitButtons[i].addActionListener(this);
            buttonPanel.add(digitButtons[i]);
        }

        operatorButtons = new Button[4];
        operatorButtons[0] = new Button("+");
        operatorButtons[1] = new Button("-");
        operatorButtons[2] = new Button("*");
        operatorButtons[3] = new Button("/");
        for (Button operatorButton : operatorButtons) {
            operatorButton.addActionListener(this);
            buttonPanel.add(operatorButton);
        }

        clearButton = new Button("C");
        clearButton.addActionListener(this);
        buttonPanel.add(clearButton);

        equalsButton = new Button("=");
        equalsButton.addActionListener(this);
        buttonPanel.add(equalsButton);

        currentInput = "";

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.equals("C")) {
            currentInput = "";
            displayField.setText(currentInput); // Clear the display field
        } else if (command.equals("=")) {
            // Evaluate the expression and display the result
            try {
                double result = evaluateExpression(currentInput);
                displayField.setText(String.valueOf(result));
            } catch (ArithmeticException ex) {
                displayField.setText("Error");
            }
        } else {
            currentInput += command;
            displayField.setText(currentInput); // Update display field with current input
        }
    }

    private double evaluateExpression(String expression) {
        // Split the expression into operands and operator
        String[] tokens = expression.split(" ");
        double operand1 = Double.parseDouble(tokens[0]);
        String operator = tokens[1];
        double operand2 = Double.parseDouble(tokens[2]);

        // Perform the arithmetic operation based on the operator
        switch (operator) {
            case "+":
                return operand1 + operand2;
            case "-":
                return operand1 - operand2;
            case "*":
                return operand1 * operand2;
            case "/":
                if (operand2 == 0) {
                    throw new ArithmeticException("Division by zero");
                }
                return operand1 / operand2;
            default:
                throw new IllegalArgumentException("Invalid operator");
        }
    }

    public static void main(String[] args) {
        SimpleCalculator calculator = new SimpleCalculator();
        calculator.setVisible(true);
    }
}

