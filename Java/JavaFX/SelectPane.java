package application;

//Description: SelectPane displays a list of available courses
//from which a user can select and compute total number of students in multiple courses.

import java.awt.List;
import java.util.ArrayList;

import javafx.event.ActionEvent; //**Need to import
import javafx.event.EventHandler; //**Need to import
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

/**
* SelectPane displays a list of available courses from which a user
* can select and compute total number of students for selected courses.
*/
public class SelectPane extends BorderPane {

    //declare instance varibales
    private ArrayList<Course> courseList;
    int members;
    VBox checkboxContainer = new VBox();
    Label toplabel = new Label("Select Courses");
	Label bottomlabel = new Label("The total number of students is ");



    public SelectPane(ArrayList<Course> list) {
        /* ------------------------------ */
        /* Instantiate instance variables */
        /* ------------------------------ */
    	

        this.courseList = list;
       // ScrollPane sp = new ScrollPane();
        
        


        // Wrap checkboxContainer in ScrollPane so formatting is
        // correct when many courses are added
        //sp.setContent(checkboxContainer);
        
        // Setup layout
        this.setTop(toplabel);
        this.setBottom(bottomlabel);
        this.setCenter(checkboxContainer);

        //create an empty pane where you can add check boxes later
        //checkboxContainer.getChildren().add(new CheckBox("testing box"));


        //SelectPane is a BorderPane - add the components here



    } // end of SelectPane constructor

    // This method uses the newly added parameter Course object
    // to create a CheckBox and add it to a pane created in the constructor
    // Such check box needs to be linked to its handler class
    public void updateCourseList(Course newcourse) {
        // Create checkbox for new course with appropriate text
    	CheckBox checkbox = new CheckBox(newcourse.toString());
    	
        // Bind checkbox toggle action to event handler
    	checkbox.setOnAction(new SelectionHandler(newcourse.getNumStudents()));
        // Passes the number of students in each course to the handler. When the checkbox is
        // toggled, this number will be added/subtracted from the total number of selected students


        // Add new checkbox to checkbox container
    	checkboxContainer.getChildren().add(checkbox);
    	//System.out.println("i am here");

    } // end of updateCourseList method

    /**
     * SelectionHandler This class handles a checkbox toggle event. When the
     * checkbox is toggled, this number will be added/subtracted from the total
     * number of selected students.
     */
    private class SelectionHandler implements EventHandler<ActionEvent> {
        // Instance variable for number of students associated with a given course/checkbox
        private int numStudents;


        public SelectionHandler(int nums) {
            this.numStudents = members; // Set instance variable
        } // end of SelectionHandler constructor

        //over-ride the abstract method handle
        public void handle(ActionEvent event) {
            // Get the object that triggered the event, and cast it to a checkbox, since
            // only a course checkbox
            // can trigger the SelectionHandler event. The cast is necessary to have access
            // to the isSelected() method
        	CheckBox chk = (CheckBox) event.getSource();
        	
        	if (chk.isSelected()) {
        		for(int i =0 ; i<courseList.size();i++) {
           		 if( courseList.get(i).toString().equals(chk.getText())) {
           			 numStudents=courseList.get(i).getNumStudents()+numStudents;
           			bottomlabel.setText("The total number of students is "+ numStudents);
           		 }
           	 }
        		
        	}
        	if (chk.isSelected()==false) {
        		for(int i =0 ; i<courseList.size();i++) {
              		 if( courseList.get(i).toString().equals(chk.getText())) {
              			 numStudents=numStudents -courseList.get(i).getNumStudents();
              			bottomlabel.setText("The total number of students is "+ numStudents);
              		 }
        		}
        	}


            // Update the label with the new number of selected students

        } // end handle method
    } // end of SelectHandler class
} // end of SelectPane class
