# ShelfSync 


## Progress update

| Name           | Progress Done  | Percentage of expected |
|----------------|----------------|------------------------|
| Matiss        | Working closely with Nicolas and Bheeni to be able to start combining the two systems. Assisting Bheeni in splitting the master HTML | 90% |
| Kristiana        | Working on poster to present on May 8th | 100% of none|
| Bheeni        | Splitting the main HTML. | 80%|
| Nicolas         | Change to the correct front end. Integrate dahsboard API Calls. Make buttons work (realizing the product addition pipeline)| 50% |

#### Plans for next week:

Nikolas - Finish the project to be ready for testing
Bheeni - Work with Nikolas on the merge
Kristiana - Will try working on the landing page. Mom isn't home, so workload may be reduced. No clue on how the landing page works - will try to figure thigs out.
Matiss - Work with Nicolas to merge frontend with the backend in an aim to ensure that it works together well.


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

