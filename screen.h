class screen
{
public:
   screen(); 												// default constructor
    screen(screen const & that);							// copy constructor
    screen(screen && that) noexcept;						// move constructor
    screen & operator = (screen const & that); 				// copy assignment
    screen & operator = (screen && that) noexcept;			// move assignment
    ~screen();												// destructor

    int dmin() const;										// getter for dmin
    int dmax() const;										// getter for dmax

    void display() const;									// display screen

    void clear();											// clear the screen
    void axes(char s);										// show both axes using symbol s

    void point(int x, int y, char s);						// plot a point using coordinate (x,y) and symbol s
    void ellipse(int x, int y, int a, int b, char s);		// plot an ellipse using center (x,y), radii a and b, and symbol s
    void polygon(int x, int y, int n, int l, char s);		// plot a polygon using center (x,y), n sides, length l, and symbol s

    void line(int x, int y, int xp, int yp, char s);		// plot a line from (x,y) to (xp, yp) using symbol s

private:
    // low lovel function to plot a single point  since y : x ratio is not 1, x is multiplied if r is true
    void plot(double x, double y, char s);			// plot a point
    int const dim = 20;								// default dimension
    double const ratio = 2.23;						// aspect ratio
    double const pi = acos(-1);						// pi value
    int mWidth, mHeight;							// width and height
    char ** mBoard;									// 2d screen board
};
