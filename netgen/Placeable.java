public abstract class Placeable {
    public double linelen;
    public double offsetx, offsety;

    public abstract String getName ();
    public abstract void flipIt ();
    public abstract int getHeight ();
    public abstract int getWidth ();
    public abstract double getPosX ();
    public abstract double getPosY ();
    public abstract void setPosXY (double leftx, double topy);
    public abstract Network[] getExtNets ();

    public void parseManual (String[] words, int i)
            throws Exception
    {
        for (; i < words.length; i ++) {
            switch (words[i].toLowerCase ()) {
                case "flip": {
                    flipIt ();
                    break;
                }
                case "offset": {
                    offsetx = Math.round (Double.parseDouble (words[++i]) * 20.0) / 2.0;
                    offsety = Math.round (Double.parseDouble (words[++i]) * 20.0) / 2.0;
                    break;
                }
                default: {
                    throw new Exception ("unknown keyword " + words[i]);
                }
            }
        }
    }
}
