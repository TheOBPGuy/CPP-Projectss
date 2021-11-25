bool pathFound(Position p) {
    if (p is finish) return true;

    foreach option O from p {
        boolean isThereAPath = pathFound(O);
        if (isThereAPath) return true; // We found a path using Option O
    }
    // We have tried all options from this position and none of the options lead
    // to finish. Hence there is no solution possible to finish

    return false;
}
