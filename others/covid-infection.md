---
date:   2024-07-30
---

# Covid Infection

It's covid time, people come and go to the offices. Given the initial infected persons, and people access history, find out how many people are infected.

Example, initial infected [A]
Building access
[A, building 1, enter 100, exit 300]
[B, building 1, enter 150, exit 450]
[C, building 2, enter 200, exit 300]

## Simulation and array scan
It requires two set of events, start time events and exit events. 

Also, two other helper data structure is need, one to record a person's start infection time, the other to mark a building's end infection time.

## Java Code
<pre>
<code>
class Solution {
  public class Event {
    char user;
    int building;
    int startTime;
    int exitTime;
    // 1 means enter, -1 means exit.
    int eventType;
  }
  public static int InfectionCount(Event[] events, char[] initialInfections) {
    HashMap<Character, Integer> userInfectionStart = new HashMap<>();
    for (char user : initialInfections) {
      userInfectionStart.put(user, 0);
    }
    HashMap<Integer, Integer> buildingInfectionEnd = new HashMap<>();
    // Sort event by start TS
    // TBD
    for (Event event : events) {
      if (event.type == 1) {  // enter event
        if (userInfectionStart.containsKey(event.user) && // user infected, affecting the building
            userInfectionStart.get(user) < event.startTime) {
            buildingInfectionEnd.put(Math.max(buildingInfectionEnd.getOrDefault(event.building, 0),
                                              event.exitTime));
        } else {
          // User is not infected, check if building is infected and affect the user
          if (buildingInfectionEnd.containsKey(event.building) &&
              buildingInfectionEnd.get(event.building) > event.startTime) {
              userInfectionStart.put(event.user, event.startTime);
              buildingInfectionEnd.put(Math.max(buildingInfectionEnd.getOrDefault(event.building, 0),
                                                event.exitTime));
          }
        }
      } else {  // exit event
        // When an user enter, building is okay, but when exit, building may be infected
        if (buildingInfectionEnd.getOrDefault(event.building, 0) > event.exitTime) {
          // How to update userInfection start? Also needs building infection start?
          // TBD
          userInfectionStart.put(event.user, event.exitTime);  // okay, as others affected user
        }
      }
    }
  }

  public static void main(String[] args) {
    return 0;
  }
}
</code>
</pre>

## Simulate with easier data structure
Keep the state in an easier way
Who's in the building: HashSet<Integer, HashSet<Character>> buildingUsers;
Who are affected: HashSet<Character>
No need to keep timestamp, as the simulation is real time, and process every event

Answer by chatGPT
## Java Code
<pre>
<code>
import java.util.*;

class PersonEvent {
    String person;
    String building;
    int time;
    boolean isEnter;

    PersonEvent(String person, String building, int time, boolean isEnter) {
        this.person = person;
        this.building = building;
        this.time = time;
        this.isEnter = isEnter;
    }
}

public class CovidInfectionSimulation {
    public static void main(String[] args) {
        // Initial infected persons
        Set<String> infected = new HashSet<>(Arrays.asList("A"));

        // Building access history
        List<PersonEvent> events = new ArrayList<>();
        events.add(new PersonEvent("A", "1", 100, true));
        events.add(new PersonEvent("A", "1", 300, false));
        events.add(new PersonEvent("B", "1", 150, true));
        events.add(new PersonEvent("B", "1", 450, false));
        events.add(new PersonEvent("C", "2", 200, true));
        events.add(new PersonEvent("C", "2", 300, false));

        // Sort events by time
        events.sort(Comparator.comparingInt(e -> e.time));

        // Track current occupancy of each building
        Map<String, Set<String>> buildingOccupancy = new HashMap<>();

        // Process each event
        for (PersonEvent event : events) {
            String person = event.person;
            String building = event.building;

            // Initialize the building occupancy set if not present
            buildingOccupancy.putIfAbsent(building, new HashSet<>());

            if (event.isEnter) {
                // Person enters the building
                buildingOccupancy.get(building).add(person);

                // Check for infection spread
                if (infected.contains(person)) {
                    // Infect everyone currently in the building
                    infected.addAll(buildingOccupancy.get(building));
                } else {
                    // Check if person gets infected
                    for (String occupant : buildingOccupancy.get(building)) {
                        if (infected.contains(occupant)) {
                            infected.add(person);
                            break;
                        }
                    }
                }
            } else {
                // Person exits the building
                buildingOccupancy.get(building).remove(person);
            }
        }

        // Output the number of infected people
        System.out.println("Number of infected people: " + infected.size());
    }
}
</code>
</pre>
