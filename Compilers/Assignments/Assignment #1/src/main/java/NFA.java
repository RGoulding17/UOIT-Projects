public class NFA {
    public NFA addStates(int... states) {
        return this;
    }

    public NFA start(int state) {
        return this;
    }

    public NFA transition(int start, int end, char symbol) {
        return this;
    }

    public NFA epsilon(int start, int end) {
        return this;
    }

    public NFA finalStates(int... states) {
        return this;
    }

    public boolean accept(String s) {
        return false;
    }
}
