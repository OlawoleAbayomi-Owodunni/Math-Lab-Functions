/*==============================================================================
Do not edit any code in this file!!!


██████   ██████      ███    ██  ██████  ████████     ███████ ██████  ██ ████████
██   ██ ██    ██     ████   ██ ██    ██    ██        ██      ██   ██ ██    ██
██   ██ ██    ██     ██ ██  ██ ██    ██    ██        █████   ██   ██ ██    ██
██   ██ ██    ██     ██  ██ ██ ██    ██    ██        ██      ██   ██ ██    ██
██████   ██████      ██   ████  ██████     ██        ███████ ██████  ██    ██


████████ ██   ██ ██ ███████     ███████ ██ ██      ███████ ██
   ██    ██   ██ ██ ██          ██      ██ ██      ██      ██
   ██    ███████ ██ ███████     █████   ██ ██      █████   ██
   ██    ██   ██ ██      ██     ██      ██ ██      ██
   ██    ██   ██ ██ ███████     ██      ██ ███████ ███████ ██

==============================================================================*/
#include "Graph.h"
#include <cassert>
#include"ThickLine.h"

void Graph::drawGraph() {


    sf::Vertex axes[5];

    float unit = Unit;
    axes[0].position = sf::Vector2f(0, unit);
    axes[0].color = sf::Color::White;
    axes[1].position = sf::Vector2f(0, 0);
    axes[1].color = sf::Color::White;
    axes[2].position = sf::Vector2f(unit, 0);
    axes[2].color = sf::Color::White;
    axes[3].position = sf::Vector2f(unit, unit);
    axes[3].color = sf::Color::White;
    axes[4].position = sf::Vector2f(0, unit);
    axes[4].color = sf::Color::White;
    window.draw(axes, 5, sf::LineStrip);

    sf:Color ticKColor = sf::Color::White;
    const int NUM_TICKS = 22;
    sf::Vertex ticks[NUM_TICKS * 2];
    for (int i = 0; i < NUM_TICKS * 2; i++) {
        ticks[i].color = ticKColor;
    }
    float tickLength = 0.02 * unit;
    int i = 0;
    for (int t = 0; t <= unit; t+=(unit/10)) {
        ticks[i++].position = sf::Vector2f((float)t, 0);
        ticks[i++].position = sf::Vector2f((float)t, -tickLength);
    }
    for (int t = 0; t <= unit; t += (unit / 10)) {
        ticks[i++].position = sf::Vector2f(0, (float)t );
        ticks[i++].position = sf::Vector2f(-tickLength, (float)t );
    }


    window.draw(ticks, NUM_TICKS * 2, sf::Lines);

    float textOffset = unit/20.0f;
    int labelTextSize = 40;
    int axisTextSize = 25;

    centredText("t", sf::Vector2f(unit/2, -textOffset), labelTextSize);
    centredText("f(t)", sf::Vector2f(-textOffset, unit / 2), labelTextSize,true);
    centredText("0.0", sf::Vector2f(0, -textOffset), axisTextSize);
    centredText("1.0", sf::Vector2f(unit, -textOffset), axisTextSize);
    centredText("0.0", sf::Vector2f(-textOffset, 0), axisTextSize, true);
    centredText("1.0", sf::Vector2f(-textOffset, unit), axisTextSize, true);


    for (auto& c : curves) {
        PointList q;
        int i = 0;
        ThickLine::convert(c->points, q, c->thickness);
        for (auto& p : q) {
            line[i].position = sf::Vector2f(p.x*unit, p.y*unit);
            line[i].color = c->color;
            i++;
        }
        window.draw(line, i, sf::TriangleStrip);
    }    
}

void Graph::addPoint(int curve, sf::Vector2f point) {
    assert(curves[curve]->points.size() < MAX_POINTS);
    curves[curve]->points.push_back(point);

}

void Graph::reset() {
    for (auto& c : curves) c->points.clear();
}
