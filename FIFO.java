import java.util.Arrays;
import java.util.Scanner;

public class FIFO {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of frames: ");
        int frameCount = scanner.nextInt();

        System.out.print("Enter the number of pages: ");
        int pageCount = scanner.nextInt();

        System.out.println("Enter the reference string: ");
        int[] referenceString = new int[pageCount];
        for (int i = 0; i < pageCount; i++) {
            referenceString[i] = scanner.nextInt();
        }

        int[] frames = new int[frameCount];
        Arrays.fill(frames, -1); // Initialize frames with -1 indicating empty

        int pageFaults = 0;
        int currentIndex = 0;

        System.out.println("Page Replacement Process:");
        for (int page : referenceString) {
            boolean pageHit = false;

            // Check if the page is already in the frame
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == page) {
                    pageHit = true;
                    break;
                }
            }

            // If page is not found in frames, perform page replacement
            if (!pageHit) {
                System.out.println("Page " + page + " caused a page fault.");
                frames[currentIndex] = page;
                currentIndex = (currentIndex + 1) % frameCount;
                pageFaults++;
            }

            // Display current frame status after each reference
            System.out.println("Current Frames: " + Arrays.toString(frames));
        }

        System.out.println("Total Page Faults: " + pageFaults);
    }
}
