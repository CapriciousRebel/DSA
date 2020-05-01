import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private int size;
    private boolean[] grid_site;
    private int openSiteCount;

    private int virtualTopIndex;
    private int virtualBottomIndex;

    // Weighted quick union-find data structure
    // to calculate percolation
    private WeightedQuickUnionUF ufForPercolation;

    // Weighted quick union-find data structure
    // to calculate fullness (without bottom virtual site)
    private WeightedQuickUnionUF ufForFullness;

    // Create n-by-n grid, with all grid_site blocked
    public Percolation(int n) {
        if (n < 1) {
            throw new IllegalArgumentException("Grid must have at least one row and column");
        }

        size = n;
        int gridSize = (n * n) + 2; // with two virtual grid_site
        grid_site = new boolean[gridSize];
        openSiteCount = 0;

        // init and open virtual grid_site
        virtualTopIndex = 0;
        virtualBottomIndex = (size * size) + 1;
        grid_site[virtualTopIndex] = true;
        grid_site[virtualBottomIndex] = false;

        ufForPercolation = new WeightedQuickUnionUF(gridSize);
        ufForFullness = new WeightedQuickUnionUF(gridSize);

        // connect top and bottom rows to virtual grid_site
        for (int col = 1; col <= size; col++) {
            int rowTop = 1;
            int siteTopIndex = getIndexByRowAndColumn(rowTop, col);
            ufForPercolation.union(virtualTopIndex, siteTopIndex);
            ufForFullness.union(virtualTopIndex, siteTopIndex);

            int rowBottom = size;
            int siteBottomIndex = getIndexByRowAndColumn(rowBottom, col);
            ufForPercolation.union(virtualBottomIndex, siteBottomIndex);
        }
    }

    // Open site (row, col) if it is not open already
    public void open(int row, int col) {
        int siteIndex = getIndexByRowAndColumn(row, col);
        if (grid_site[siteIndex]) {
            return;
        }

        openSiteCount++;
        grid_site[siteIndex] = true;

        // connect with left neighbor
        if (col > 1 && isOpen(row, col - 1)) {
            int siteLeftIndex = getIndexByRowAndColumn(row, col - 1);
            ufForPercolation.union(siteIndex, siteLeftIndex);
            ufForFullness.union(siteIndex, siteLeftIndex);
        }

        // connect with right neighbor
        if (col < size && isOpen(row, col + 1)) {
            int siteLeftIndex = getIndexByRowAndColumn(row, col + 1);
            ufForPercolation.union(siteIndex, siteLeftIndex);
            ufForFullness.union(siteIndex, siteLeftIndex);
        }

        // connect with top neighbor
        if (row > 1 && isOpen(row - 1, col)) {
            int siteLeftIndex = getIndexByRowAndColumn(row - 1, col);
            ufForPercolation.union(siteIndex, siteLeftIndex);
            ufForFullness.union(siteIndex, siteLeftIndex);
        }

        // connect with bottom neighbor
        if (row < size && isOpen(row + 1, col)) {
            int siteLeftIndex = getIndexByRowAndColumn(row + 1, col);
            ufForPercolation.union(siteIndex, siteLeftIndex);
            ufForFullness.union(siteIndex, siteLeftIndex);
        }
    }

    // If site (row, col) open
    public boolean isOpen(int row, int col) {
        int siteIndex = getIndexByRowAndColumn(row, col);

        return grid_site[siteIndex];
    }

    // If site (row, col) full
    public boolean isFull(int row, int col) {
        int siteIndex = getIndexByRowAndColumn(row, col);

        return (isOpen(row, col) && ufForFullness.connected(virtualTopIndex, siteIndex));
    }

    // Number of open grid_site
    public int numberOfOpenSites() {
        return openSiteCount;
    }

    // If the system percolate
    public boolean percolates() {
        // if grid with one site - check if it"s open
        if (size == 1) {
            int siteIndex = getIndexByRowAndColumn(1, 1);
            return grid_site[siteIndex];
        }

        return ufForPercolation.connected(virtualTopIndex, virtualBottomIndex);
    }

    // Get site"s index to be represented in array
    private int getIndexByRowAndColumn(int row, int col) {
        validateBounds(row, col);

        return ((row - 1) * size) + col;
    }

    // Check if row and column values are in range of grid size
    private void validateBounds(int row, int col) {
        if (row > size || row < 1) {
            throw new IndexOutOfBoundsException("Row index is out of bounds");
        }

        if (col > size || col < 1) {
            throw new IndexOutOfBoundsException("Column index is out of bounds");
        }
    }

    // Test client (optional)
    public static void main(String[] args) {
        Percolation percolation = new Percolation(2);

        StdOut.println("percolates = " + percolation.percolates());

        StdOut.println("isOpen(1, 2) = " + percolation.isOpen(1, 2));
        StdOut.println("isFull(1, 2) = " + percolation.isFull(1, 2));
        StdOut.println("open(1, 2)");
        percolation.open(1, 2);
        StdOut.println("isOpen(1, 2) = " + percolation.isOpen(1, 2));
        StdOut.println("isFull(1, 2) = " + percolation.isFull(1, 2));
        StdOut.println("numberOfOpenSites() = " + percolation.numberOfOpenSites());
        StdOut.println("percolates() = " + percolation.percolates());

        StdOut.println("isOpen(2, 1) = " + percolation.isOpen(2, 1));
        StdOut.println("isFull(2, 1) = " + percolation.isFull(2, 1));
        StdOut.println("open(2, 1)");
        percolation.open(2, 1);
        StdOut.println("isOpen(2, 1) = " + percolation.isOpen(2, 1));
        StdOut.println("isFull(2, 1) = " + percolation.isFull(2, 1));
        StdOut.println("numberOfOpenSites() = " + percolation.numberOfOpenSites());
        StdOut.println("percolates() = " + percolation.percolates());

        StdOut.println("isOpen(1, 1) = " + percolation.isOpen(1, 1));
        StdOut.println("isFull(1, 1) = " + percolation.isFull(1, 1));
        StdOut.println("open(1, 1)");
        percolation.open(1, 1);
        StdOut.println("isOpen(1, 1) = " + percolation.isOpen(1, 1));
        StdOut.println("isFull(1, 1) = " + percolation.isFull(1, 1));
        StdOut.println("numberOfOpenSites() = " + percolation.numberOfOpenSites());
        StdOut.println("percolates() = " + percolation.percolates());
    }
}