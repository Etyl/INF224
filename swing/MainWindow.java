package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

//import swing.Client;

public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private TextField searchField;
    private JButton searchButton;
    private Client client;

    public MainWindow() {
        // Create the text area
        textArea = new JTextArea();
        // Create the buttons
        searchField = new TextField();
        searchButton = new JButton("Search");
        connectCient();

        // Add action listeners to the buttons
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String request = "display " + searchField.getText();
                textArea.append(client.send(request)+"\n");
            }
        });

        // Create the main window
        setTitle("Main Window");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Add components to the main window
        add(new JScrollPane(textArea), BorderLayout.CENTER);
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(searchField);
        buttonPanel.add(searchButton);
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
                textArea.append(client.send("display photo1 \n"));
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
        toolBar.add(searchField);
        toolBar.add(searchButton);

        // Set the size and make the window visible
        pack();
        setSize(600, 400);
        setVisible(true);
    }

    private void connectCient() {

        try {
            client = new Client();
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to to " + client.getHost() + ":" + client.getPort());
            return;
        }

        System.out.println("Client connected to " + client.getHost() + ":" + client.getPort());

    }

}