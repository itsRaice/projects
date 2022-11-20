package application;
//Assignment 6: ASU - CSE 205
//Name: Aryan Rai

//StudentID: 1218775493
//Lecture Date and Time: MWF 10:10am
//Description: GeneratePane creats a pane where a user can enter
//course information and create a list of available courses.

/* --------------- */
/* Import Packages */
/* --------------- */

import java.util.ArrayList;

import javafx.event.ActionEvent; //**Need to import
import javafx.event.EventHandler; //**Need to import

//JavaFX classes
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

/**
* GeneratePane builds a pane where a user can enter a course
* information and create a list of available courses.
*/
public class GeneratePane extends HBox {
 /* ------------------ */
 /* Instance variables */
 /* ------------------ */
	
//output for adding courses
TextArea textArea = new TextArea(); 

//labels for promiting inputs
Label courseLabel = new Label("Course Name");
Label instLabel = new Label("Name of instructor");
Label uniLabel = new Label("Name of University");
Label stuLabel = new Label("Number of students");
Label resultbox = new Label("");

//input fields 
TextField courseField = new TextField();
TextField instField = new TextField();
TextField uniField = new TextField();
TextField stuField = new TextField();

 ArrayList<Course> courseList;
 
 private SelectPane selectPane; // The relationship between GeneratePane and SelectPane is Aggregation
 //declare and init

 /**
  * CreatePane constructor
  *
  * @param list   the list of courses
  * @param sePane the SelectPane instance
  */
 public GeneratePane(ArrayList<Course> list, SelectPane sePane) {
     /* ------------------------------ */
     /* Instantiate instance variables */
     /* ------------------------------ */
	 courseList = new ArrayList<Course>();
	 selectPane = new SelectPane(courseList);
	 courseList = list;
	 selectPane = sePane;

     //initialize each instance variable (textfields, labels, textarea, button, etc.)
		//and set up the layout
	 

		//create a GridPane to hold labels & text fields.
		//you can choose to use .setPadding() or setHgap(), setVgap()
		//to control the spacing and gap, etc.
	 
	 //adding all the nodes to the pane
	 GridPane gridPane = new GridPane();
	 gridPane.add(courseLabel, 0, 0);
	 gridPane.add(courseField, 1, 0);
	 gridPane.add(instLabel, 0, 1);
	 gridPane.add(instField, 1, 1);
	 gridPane.add(uniLabel, 0, 2);
	 gridPane.add(uniField, 1, 2);
	 gridPane.add(stuLabel, 0, 3);
	 gridPane.add(stuField, 1, 3);
	 Button btAdd = new Button("Add a Course");
	 gridPane.add(resultbox,0,4);
	 gridPane.add(btAdd, 1, 4);
	 
	 //handle button being pressed
	 btAdd.setOnAction(new ButtonHandler());
	 
	 
		// Set both left and right columns to 50% width (half of window)
		//ColumnConstraints halfWidth = new ColumnConstraints();
		//halfWidth.setPercentWidth(50);
     //gridPane.getColumnConstraints().addAll(halfWidth, halfWidth);
		//You might need to create a sub pane to hold the button
	 
	 //display on the pane
     this.getChildren().addAll(gridPane,textArea);
     
     
		//Set up the layout for the left half of the GeneratePane.

		//the right half of the GeneratePane is simply a TextArea object
		//Note: a ScrollPane will be added to it automatically when there are no more space
		//Add the left half and right half to the GeneratePane


		//Note: GeneratePane extends from HBox
		//register/link source object with event handler
             // Bind button click action to event handler
     
     


 } // end of constructor

 /**
  * ButtonHandler ButtonHandler listens to see if the button "Add a course" is pushed
  * or not, When the event occurs, it asks for course and instructor name, number of students enrolled,
  * and its university information from the relevant text fields, then create a
  * new course and adds it to the courseList. Meanwhile it will display the course's
  * information inside the text area. using the toString method of the Course
  * class. It also does error checking in case any of the text fields are empty,
  * or a non-numeric value was entered for number of student
  */
 private class ButtonHandler implements EventHandler<ActionEvent> {
     /**
      * handle Override the abstract method handle()
      */
     public void handle(ActionEvent event) {
         // Declare local variables
    	 int stunum;
         Course newCourse;
         Instructor inst;
         String restext = textArea.getText();
         

         // If any field is empty, set isEmptyFields flag to true
         

         // Display error message if there are empty fields


         // If all fields are filled, try to add the course
         try {
                 /*
                  * Cast students Field to an integer, throws NumberFormatException if unsuccessful
                  */
        	 //convert field text to integer
        	 stunum = Integer.parseInt(stuField.getText());
        	 
        	 //create instructor object
        	 inst = new Instructor("", instField.getText(),"",0);
        	 
        	 //create new course object
        	 newCourse = new Course(courseField.getText(),inst,uniField.getText(),stunum);
        	 


                 // Data is valid, so create new Department object and populate data

                 // Loop through existing departments to check for duplicates
                 // and if exist do not add it to the list and display a message
        	 
        	 
        	 //using toString to compare if 2 courses are equal
        	 for(int i =0 ; i<courseList.size();i++) {
        		 if( courseList.get(i).toString().equals(newCourse.toString())) {
        			 throw new Exception();
        		 }
        	 }
        	 
        	 //add course to array list
        	 courseList.add(newCourse);
        	 
        	 //show results
        	 textArea.setText(restext + "\n" + newCourse.toString());
        	 selectPane.updateCourseList(newCourse);
        	 resultbox.setText("Course Added");
        	 
        	 //reset input fields
        	 courseField.setText("");
        	 instField.setText("");
        	 uniField.setText("");
        	 stuField.setText("");
        	 




                 // else course is not a duplicate, so display it and add it to list

             } //end of try
             catch (NumberFormatException e) {
                 // If the number of students entered was not an integer, display an error
            	 resultbox.setText("Enter an integer for number of students");

             } 
             catch (Exception e) {
                 // Catches generic exception and displays message
                 // Used to display 'Course is not added - already exist' message if course already exist
            	 resultbox.setText("Course is not added - already exist");
            	 //System.out.println(e);
            	 //resultbox.setText("is it here");

             }

        
     } // end of handle() method
 } // end of ButtonHandler class
 
} // end of GeneratePane class


