#include <stdio.h>
#include <string.h>


void printMovieInfo(const char *title, const char *type, int duration, const char *showtime) {
    printf("Title: %s\n", title);
    printf("type: %s\n", type);
    printf("Duration: %d minutes\n", duration);
    printf("Showtime: %s\n\n", showtime);
}


void sendEmailNotification(const char *movieTitle, const char *showtime) {
    printf("Sending an email notification for movie '%s' at showtime '%s'\n", movieTitle, showtime);
}


void sendTextNotification(const char *movieTitle, const char *showtime) {
    printf("Sending a text message notification for movie '%s' at showtime '%s'\n", movieTitle, showtime);
}

int main() {

    const char *movies[] = {"Movie 1", "Movie 2", "Movie 3"};
    const char *types[] = {"Action", "Comedy", "Romantic"};
    int durations[] = {120, 105, 90};
    const char *showtimes[] = {"10:00 AM", "2:30 PM", "6:45 PM"};

    const int numMovies = sizeof(movies) / sizeof(movies[0]);

    printf("Available Movies:\n");
    for (int i = 0; i < numMovies; ++i) {
        printMovieInfo(movies[i], types[i], durations[i], showtimes[i]);
    }

    printf(" Movie 1 ----> press 0\n Movie 2 ----> press 1 \n Movie 3 ----> press 2 \n \n");

    int userChoice;
    printf("Enter the movie number you want to see: ");
    scanf("%d", &userChoice);

    if (userChoice >=0 && userChoice < numMovies) {
        const char *selectedMovie = movies[userChoice];
        const char *selectedShowtime = showtimes[userChoice];



        int preferredNotificationMethod ;
     printf("\nEnter notification method:\nEmail ---> 1 \nText message --> 2\n");
    scanf("%d",&preferredNotificationMethod );
        if (preferredNotificationMethod == 1) {
            sendEmailNotification(selectedMovie, selectedShowtime);
        } else if (preferredNotificationMethod == 2) {
            sendTextNotification(selectedMovie, selectedShowtime);
        } else {
            printf("Invalid notification preference. No notification sent.\n");
        }
    } else {
        printf("Invalid movie choice.\n");
    }

    return 0;
}
