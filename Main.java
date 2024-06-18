abstract class Anime {
    String title;
    int year;
   
    abstract void displayInfo();
}

class Manga extends Anime {
    int[] pages;

    public Manga(String title, int year, int[] pages) {
        this.title = title;
        this.year = year;
        this.pages = pages;
    }

    void displayInfo() {
        int totalPages = 0;
        for (int page : pages) {
            totalPages += page;
        }
        System.out.println("Manga: " + title + " (" + year + ") has " + totalPages + " pages in total.");
    }
}

class AnimeSeries extends Anime {
    int episodes;

    public AnimeSeries(String title, int year, int episodes) {
        this.title = title;
        this.year = year;
        this.episodes = episodes;
    }

    void displayInfo() {
        int totalMinutes = episodes * 24; // Assuming each episode is 24 minutes long
        System.out.println("Anime Series: " + title + " (" + year + ") will take " + totalMinutes + " minutes to watch all episodes.");
    }
}

class AnimeMovie extends Anime {
    int duration; // in minutes

    public AnimeMovie(String title, int year, int duration) {
        this.title = title;
        this.year = year;
        this.duration = duration;
    }

    void displayInfo() {
        System.out.println("Anime Movie: " + title + " (" + year + ") is " + duration + " minutes long.");
    }
}

public class Main {
    public static void main(String[] args) {
        Manga manga1 = new Manga("One Piece", 1997, new int[] {800, 900, 1000});
        Manga manga2 = new Manga("Naruto", 1999, new int[] {700, 800, 900});
        AnimeSeries animeSeries = new AnimeSeries("Attack on Titan", 2013, 89);
        AnimeMovie animeMovie = new AnimeMovie("Spirited Away", 2001, 125);

        manga1.displayInfo();
        manga2.displayInfo();
        animeSeries.displayInfo();
        animeMovie.displayInfo();
    }
}
