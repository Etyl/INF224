package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JButton button1;
    private JButton button2;
    private JButton exitButton;

    public MainWindow() {
        // Create the text area
        textArea = new JTextArea();
        // Create the buttons
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        exitButton = new JButton("Exit");

        // Add action listeners to the buttons
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Text from Button 1\n");
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Text from Button 2\n");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        // Create the main window
        setTitle("Main Window");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Add components to the main window
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(exitButton);
        add(buttonPanel, BorderLayout.SOUTH);

        // Create the menu bar
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        // Create the menu
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        // Create the menu items
        JMenuItem menuItem1 = new JMenuItem("Button 1");
        JMenuItem menuItem2 = new JMenuItem("Button 2");
        JMenuItem exitMenuItem = new JMenuItem("Exit");

        // Add action listeners to the menu items
        menuItem1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Text from Button 1\n");
            }
        });

        menuItem2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Text from Button 2\n");
            }
        });

        exitMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        // Add menu items to the menu
        menu.add(menuItem1);
        menu.add(menuItem2);
        menu.add(exitMenuItem);

        // Create the toolbar
        JToolBar toolBar = new JToolBar();
        add(toolBar, BorderLayout.NORTH);

        // Add buttons to the toolbar
        toolBar.add(button1);
        toolBar.add(button2);
        toolBar.add(exitButton);

        // Set the size and make the window visible
        pack();
        setSize(600, 400);
        setVisible(true);
    }
}