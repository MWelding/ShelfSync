# ShelfSync 


## Progress update

| Name           | Progress Done  | Percentage of expected |
|----------------|----------------|------------------------|
| Matiss        | Finished the scripting for load cells. Reads the serial connection from the esp32 into a python program which uploads data to the DB once a large enough change (offset adjusted) is measured.          |65% (hardware only remaining)|
| Kristiana        | Figuring out the method for getting the website code            | 10% |
| Bheeni        | Figured out design of the dash (in her head)            | 40% |
| Nicolas         | Re-made the strucutre of the connection between the front-end and back-end. Started adaptation of front-end (format change)        | 40% |

#### Plans for next week:

Nikolas - Adapt sent-in front-end to the back-end. Begin DB creation for product-pipeline (auth already complete)
Bheeni - Finish the design and export the code for the homepage, product addition pipeline and user settings
Kristiana - Out of commision, has 40 minutes on Thurs, will help Bheeni with front-end
Matiss - Prepare hardware for initial testing. 3D print components and screw together test bed. Upload script to ESP32, esnure python program works as expected and is injecting data properly. 


<h2>Brainstorming:</h2

Instead of making a project that was only hardware or only software, we wanted to make an amalgamation of electronics and software. We looked at real-world crises, hoping to make a new solution to an existing and relevant issue. We approached this in a Problem Definition and Elimination manner. First, we defined the things we didn’t want to do, and found common ground in the solutions unmentioned. Then, by combining facets of each of our propositions we came up with ShelfSync.

The general idea of our project is to enable user based smart tracking for perishable products inside the fridge. The system uses barcode scanning and smart weight sensing to enable tracking of weight, location and expiry dates. The system will employ a user UI that enables easy viewing and tracking of goods. This system will also alert the viewer when a product is near end-of-life. 
Simply, the 2 parts of the project include: Hardware (barcode scanner, sensors), and Software (Web Server, UI) which integrate to form a unique and smart system to sync your shelves to your mobiles.

By utilizing two sensor systems (scale and barcode scanner) and user input for expiry date, we can accurately show different data for each individual product. The hardware consists of sensors, connected to a Raspberry Pi and a web server which will analyze and compile data to present it in an easy to navigate UI.

To make this process easier, we thought of starting with a select few items 
(milk and sour cream) that most people have at home. After perfecting the system for these products, we’ll expand our reach.

<h2>The steps:</h2>
User buys item
While stocking the fridge, user inputs item expiry date into UI
The as user is placing it in the fridge, the item’s barcode is scanned by the scanner on the fridge. This will give us key information about the product including its weight and components.
The shelf that the user places it on has 2-4 weight sensor arduinoes that will supply the weight data to our server
This enables us to know everytime the product has been removed and what quantity of it has been used
Next time the user wants to remove the item, they can be informed of its location using the weight sensor data
If the item has been in the fridge for longer than its expiry date suggest and still has weight other than the carton, the user will be notified that that product is expired

---

🌱 **With ShelfSync, we present a beginning** 🌱  
A beginning to a solution that can better thousands of people’s lives by promoting sustainability, reducing food waste, and making people more aware of exactly what lies on their shelves. ShelfSync can be used in so many sectors of science and humanities, and we’re excited to tap into its exponential possibilities. 🌍

