package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.io.Serial;

public class MainWindow extends JFrame {
    @Serial
    private static final long serialVersionUID = 1L;
    private final JTextArea textArea;
    private final TextField searchField;
    private final JButton searchButton;
    private final JButton playButton;
    private Client client;  

    public MainWindow() {

        // Create the text area
        textArea = new JTextArea();
        // Create the buttons
        searchField = new TextField();
        searchButton = new JButton("Search");
        playButton = new JButton("Play");
        connectClient();

        // Add action listeners to the buttons
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String request = "display " + searchField.getText();
                textArea.append(client.send(request)+"\n");
            }
        });

        playButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String request = "play " + searchField.getText();
                textArea.append(client.send(request)+"\n");
            }
        });

        // Create the main window
        setTitle("Main Window");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Add components to the main window
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        // Create the menu bar
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        // Create the menu
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        // Create the menu items
        JMenuItem menuItem1 = new JMenuItem("Change host/port");
        JMenuItem exitMenuItem = new JMenuItem("Exit");

        // Add action listeners to the menu items
        menuItem1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                createDialog();
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
        menu.add(exitMenuItem);

        // Create the toolbar
        JToolBar toolBar = new JToolBar();
        add(toolBar, BorderLayout.NORTH);

        // Add buttons to the toolbar
        toolBar.add(searchField);
        toolBar.add(searchButton);
        toolBar.add(playButton);

        // Set the size and make the window visible
        pack();
        setSize(600, 400);
        setVisible(true);
    }

    /**
     * Connects the client to the server.
     */
    private void connectClient() {

        try {
            client = new Client();
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to to " + client.getHost() + ":" + client.getPort());
            return;
        }
        System.out.println("Client connected to " + client.getHost() + ":" + client.getPort());

    }

    /**
     * Creates and displays a dialog for entering host and port information.
     */
    private void createDialog() {
    
        // Create dialog
        JDialog dialog = new JDialog(this, "Dialog", true);
        dialog.setLayout(new FlowLayout());

        // Create text field
        JTextField hostField = new JTextField(20);
        JTextField portField = new JTextField(6);

        // Create button
        JButton button = new JButton("Save host");
        // Add action listener to button
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Perform action when button is clicked
                String host = hostField.getText();
                String port = portField.getText();
                if (host != null && port != null) {
                    try {
                        client = new Client(host, Integer.parseInt(port));
                    } catch (Exception e1) {
                        textArea.append("Could not connect to " + host + ":" + port);
                    }
                }
                dialog.dispose();
            }
        });

        dialog.add(hostField);
        dialog.add(portField);
        dialog.add(button);

        // Set dialog size and visibility
        dialog.setSize(450, 200);
        dialog.setVisible(true);
    }
}